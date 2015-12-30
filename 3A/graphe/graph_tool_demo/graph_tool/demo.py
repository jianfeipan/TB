from graph_tool.all import *


def main():
    g = Graph(directed=False)
    v1 = g.add_vertex()
    v2 = g.add_vertex()
    g.add_vertex(10)
    g.add_edge(v1, v2)
    graph_draw(g, vertex_text=g.vertex_index, vertex_font_size=18)


if __name__ == "__main__":
    main()
