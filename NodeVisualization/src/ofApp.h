#pragma once
#include "ofMain.h"
#include "iostream"

class Node
{
    public:
	int data;
	Node* next;

	Node();
};

class LinkedList
{
    public:
     Node* head;

    LinkedList();

    void insertAtHead(int value);
	void insertAtTail(int value);
    void deleteHead();
    void deleteTail();
};

class ofApp : public ofBaseApp{

	public:
        LinkedList linkedList;	
		ofEasyCam  camera;
		glm::vec2  offset;

		float amplitude;


		int generateRandomNumber();
		void moveCamera(float speed);
		void displayNodes();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
