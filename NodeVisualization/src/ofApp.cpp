#include "ofApp.h"
#include "ofNode.h"

Node::Node() {
	data = 0;
	next = nullptr;
}

LinkedList::LinkedList() {
	head = nullptr;
}

void LinkedList::insertAtHead(int value)
{
	Node* node = new Node();
	node->data = value;
	node->next = head;
	head = node;
}

void LinkedList::insertAtTail(int value) {
	Node* node = new Node();
	node->data = value;
	node->next = nullptr;

	if (head == nullptr)
		head = node;
	else
	{
		Node* temp = head;

		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = node;
	}
}

void LinkedList::deleteHead() {
	if (!head) return;
	Node* temp = head;
	head = head->next;
	delete temp;
}


void LinkedList::deleteTail() {
	if (head == nullptr) return;

	if (head->next != nullptr) {
		Node* temp = head;

		while (temp->next->next != nullptr)
			temp = temp->next;

		delete temp->next;
		temp->next = nullptr;
		return;
	}

	delete head;
	head = nullptr;
}

int ofApp::generateRandomNumber() {
	return (int)(1 + (std::rand() % (1 - 50)));
}

void ofApp::moveCamera(float speed) {
	glm::vec3 currentPosition = camera.getPosition();
	float     nextPositionX   = currentPosition.x + (speed * ofGetLastFrameTime());
	camera.setPosition(nextPositionX, currentPosition.y, currentPosition.z);
}

void ofApp::displayNodes() {
	Node* temp = linkedList.head;

	if (temp != nullptr) {
		int spacing       = 1;
		ofColor black     = ofColor(0, 0, 0);
		ofColor white     = ofColor(255, 255, 255);
		
		float currentPositionY = 0;

		if (amplitude > 0)
		{
			float oscillation = amplitude   * sin(ofGetElapsedTimef() * 10);
			currentPositionY  = oscillation * offset.y;
		}
		else
		{
			currentPositionY = offset.y;
		}

		while (temp->next != nullptr)
		{
			int size = temp->data;
			glm::vec2 currentPosition = glm::vec2(offset.x * spacing, currentPositionY);

			ofDrawCircle(currentPosition, size);
			ofDrawBitmapStringHighlight(ofToString(size), currentPosition, white, black);

			temp = temp->next;
			spacing++;
		}

		if (spacing >= 2)
		{
			glm::vec2 startPosition = glm::vec2(offset.x,           offset.y);
			glm::vec2 endPosition   = glm::vec2(offset.x * spacing, offset.y);
			ofDrawLine(startPosition, endPosition);
		}
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	std::srand(time(0));
	offset    = glm::vec2(100, 100);
	amplitude = 1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	camera.begin();
	displayNodes();
	camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	std::cout << key << std::endl;

	if (key == 57356) {
		moveCamera(-250);
	}
	else if (key == 57358)
	{
		moveCamera(250);
	}
	else
	{
		switch (key)
		{
		case 'q':
			linkedList.insertAtHead(generateRandomNumber());
			break;

		case 'w':
			linkedList.insertAtTail(generateRandomNumber());
		break;

		case 'a':
			linkedList.deleteHead();
		break;

		case 's':
			linkedList.deleteTail();
		break;

		case 'e':

		break;

		case 'z':
			if (amplitude >= 5) 
				amplitude = 5;
			else
				amplitude += 0.25;
		break;

		case 'x':
			if (amplitude <= 0)
				amplitude = 0;
			else
			    amplitude -= 0.25;
			break;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
