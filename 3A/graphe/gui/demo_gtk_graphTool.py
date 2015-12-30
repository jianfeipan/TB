from gi.repository import Gtk
from graph_tool.all import *
class MyListBox(Gtk.ListBox):
	def __init__(self):
		Gtk.ListBox.__init__(self)
		self.initUI()
	def initUI(self):
		self.addRow(0,"255.255.255.255")
		self.addRow(1,"255.255.255.254")
	
	def addRow(self,index,name):
		row = Gtk.ListBoxRow()
		hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL,spacing = 10)
		row.add(hbox)
		check = Gtk.CheckButton()
		hbox.pack_start(Gtk.Label(index, xalign=0),True, True, 0)
		hbox.pack_start(Gtk.Label(name, xalign=0),True, True, 0)
		hbox.pack_start(check, True, True, 0)
		self.add(row)

class MyGraphWidget(GraphWidget):
	def __init__(self,graph, pos):
		GraphWidget.__init__(self,graph, pos, vertex_text=graph.vertex_index, display_props_size=5,vertex_font_size=10)

class MyGraph(Graph):
	def __init__(self):
		Graph.__init__(self)
		v1 = self.add_vertex(0)
		v2 = self.add_vertex(1)
		e = self.add_edge(0, 1)
    	#graph_draw(g, vertex_text=g.vertex_index, vertex_font_size=10)
		
class MyWindow(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title="MyWindow")
        self.set_default_size(700, 400)
        self.set_position(Gtk.WindowPosition.CENTER)
        
        table = Gtk.Table(14, 14, True)
        self.add(table)
        
        self.g = MyGraph()
        self.prop = self.g.new_vertex_property("vector<int>")
        self.prop[self.g.vertex(0)] = [0,0]
        self.prop[self.g.vertex(1)] = [0,100]
        self.graphWidget = MyGraphWidget(self.g,self.prop)
        
        self.label = Gtk.Label(label="Nodes :", xalign=0)
        #------------------------------------------------------
        self.listbox = MyListBox()
             
        #------------------------------------------------------
        table.attach(self.label, 0, 4, 0, 1)
        table.attach(self.listbox, 0, 4, 1, 14)
        table.attach(self.graphWidget, 5, 14, 0, 14)

    def on_button_clicked(self, widget):
        print("Hello World")
        
def main():
	win = MyWindow()
	win.connect("delete-event", Gtk.main_quit)
	win.show_all()
	Gtk.main()

if __name__ == "__main__":
    main()
