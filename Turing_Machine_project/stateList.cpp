#include "stateList.h"
#include <fstream>
#include <cassert>

using stData = std::pair<std::string, bool>;

stateList::stateList() {

}

stateList::stateList(std::vector<stData>& vec)
{
	stateBuffer = vec;
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

std::vector<stData> stateList::getBuffer() const
{
	return stateBuffer;
}

size_t stateList::size()const
{
	return stateBuffer.size();
}

void stateList::push(const stData d)
{
	stateBuffer.push_back(d);
}

//въвежда състояния докато не види състояние с име на следващото състояние halt
void stateList::input(const std::string& filename)
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

void stateList::input(const std::vector<stData>& vec)
{
	stateBuffer = vec;
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

void stateList::print()const
{
	for(size_t i =0;i<stateBuffer.size();i++) {
		std::cout << stateBuffer[i].first<< " "<<stateBuffer[i].second<<std::endl;
		
	}
}


