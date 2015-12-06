#include "Window.h"

Window::Window(){
	Window();
}

Window::Window(int n=1){
	this->size=n;
	widgets=new Widget*[size];
}

Window::~Window(){
	for(int i=0; i<size; i++){
		delete widgets[i];
	}
	delete [] widgets;
}

int Window::getSize(){
	return this->size;
}

void Window::init(){
	for(int i=0; i<size; i++){
		widgets[i]=new Button(0,0);
	}
}

void Window::draw(){
	for(int i=0; i<size; i++){
		widgets[i]->draw();
	}
}
