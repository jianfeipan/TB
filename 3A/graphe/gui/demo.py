from Tkinter import *        
class Nodeslist(Listbox):
	def __init__(self, parent):
		Listbox.__init__(self,parent,height=100)
		self.initUI()
	def initUI(self):
		li = 'Carl Patrick Lindsay Helmut Chris Gwen'.split()
		for item in li:
			self.insert(0,item)
		self.pack(side=LEFT)
    	
class NodeslistFrame(Frame):
	def __init__(self, parent):
		Frame.__init__(self, parent,padx=5,pady=5)
		self.initUI()
		
	def initUI(self):
		Label(self, text="Nodes:",anchor = NW).pack(fill=X)
		self.pack(side=LEFT)
    	
        
def main():
    root = Tk()
    root.geometry("1000x600+30+30")
    nodesList = Nodeslist(NodeslistFrame(root))
    root.mainloop()

if __name__ == "__main__":
    main()
