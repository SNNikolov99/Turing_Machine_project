#include "stateList.h"
#include <fstream>
#include <cassert>

using stData = std::pair<std::string, bool>;

stateList::stateList() {

}


stateList::~stateList()
{
	stateBuffer.clear();
}

stData stateList::operator[](int n) const
{
	assert(n < stateBuffer.size());
	return stateBuffer[n];
}

std::vector<stData> stateList::getBuffer()
{
	return stateBuffer;
}

size_t stateList::size()
{
	return stateBuffer.size();
}

void stateList::push(const stData d)
{
	stateBuffer.push_back(d);
}

//въвежда състояния докато не види състояние с име на следващото състояние halt
void stateList::setStates(std::string filename)
{
	std::ifstream is;
	is.open(filename);
	std::string newName;
	bool isFinishing;
	

	//въвеждаме данни 
	while (!is.eof()) {
		is >> newName;
		is >> isFinishing;
		stData* newPair = new stData(newName, isFinishing);
		stateBuffer.push_back(*newPair);
	}
	
	is.close();
}
	

bool stateList::isThereAState(std::string Name) {

	for (size_t i = 0; i < stateBuffer.size(); i++) {
		if (stateBuffer[i].first == Name) {
			return true;
		}
	}

	return false;
}

stData stateList::getStateByName(std::string Name) {

		if (isThereAState(Name) == false) {
			return { "halt",1 };
		}

		for (size_t i = 0; i < stateBuffer.size(); i++) {
			if (stateBuffer[i].first == Name) {
				return stateBuffer[i];
			}
		}
}

void stateList::printList()
{
	for(size_t i =0;i<stateBuffer.size();i++) {
		std::cout << stateBuffer[i].first<< " "<<stateBuffer[i].second<<std::endl;
		
	}
}


