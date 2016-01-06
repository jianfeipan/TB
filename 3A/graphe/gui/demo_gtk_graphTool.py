from gi.repository import Gtk
from graph_tool.all import *


class MyListBox(Gtk.ListBox):
    def __init__(self):
        Gtk.ListBox.__init__(self)
        self.init_ui()

    def init_ui(self):
        self.add_row(0, "255.255.255.255")
        self.add_row(1, "255.255.255.254")

    def add_row(self, index, name):
        row = Gtk.ListBoxRow()
        h_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=10)
        row.add(h_box)
        check = Gtk.CheckButton()
        h_box.pack_start(Gtk.Label(index, xalign=0), True, True, 0)
        h_box.pack_start(Gtk.Label(name, xalign=0), True, True, 0)
        h_box.pack_start(check, True, True, 0)
        self.add(row)


class MyGraphWidget(GraphWidget):
    def __init__(self, graph):
        GraphWidget.__init__(self, graph, fruchterman_reingold_layout(graph), vertex_text=graph.vertex_index,
                             display_props_size=5,
                             vertex_font_size=10,
                             vertex_size=20,
                             edge_text=graph.e_weight,
                             edge_color=graph.e_color)


class MyGraph(Graph):
    def __init__(self):
        Graph.__init__(self, directed=False)
        v_list = list(self.add_vertex(6))
        size = len(v_list)
        self.e_weight = self.new_edge_property("string")
        self.e_color = self.new_edge_property("vector<float>")
        for i in range(size):
            for j in range(i + 1, size):
                edge = self.add_edge(v_list[i], v_list[j])
                self.e_weight[edge] = '0.1'
                self.e_color[edge] = [0.0, 0.203, 0.210, 0.8]


class MyWindow(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title="MyWindow")
        self.resize(1000, 600)
        self.set_position(Gtk.WindowPosition.CENTER)

        table = Gtk.Table(14, 14, True)
        self.add(table)
        self.label = Gtk.Label(label="Nodes :", xalign=0)

        g = MyGraph()

        self.graphWidget = MyGraphWidget(g)

        self.listbox = MyListBox()

        table.attach(self.label, 0, 4, 0, 1)
        table.attach(self.listbox, 0, 4, 1, 14)
        table.attach(self.graphWidget, 5, 14, 0, 14)


def main():
    win = MyWindow()
    win.connect("delete-event", Gtk.main_quit)
    win.show_all()
    Gtk.main()


if __name__ == "__main__":
    main()
