from graph_tool.all import *
from gi.repository import Gtk

def main():
    g = Graph()
    v1 = g.add_vertex()
    v2 = g.add_vertex()
    e = g.add_edge(v1, v2)
    window = interactive_window(g, vertex_text=g.vertex_index, vertex_font_size=10)


if __name__ == "__main__":
    main()
