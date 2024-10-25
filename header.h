#pragma once
#include <string>

std::string arr[3] = {};

inline void splitName(std::string name);

inline void splitName(std::string name) {
	//Parse string
	std::string temp;
	int count = 0;
	//Same technique as the KarelGame project (context: https://github.com/AhmedRamen/KarelGame/blob/815c1cb3152ee29f64b0f9954469b9c771d5ff0e/src/tileset.h#L99-L106)
	for (char c : name) {
		if (c == ' ') {
			//Apparently trying to do arr->append(temp) actually appends to only the first one since it's a "pointer",
			//so to counter this we add [count] so it isn't a pointer (arr.append(temp) doesn't compile anyway)
			arr[count].append(temp);
			temp.clear();
			count++;
		}
		else {
			temp += c;
		}
	}
	//Append anything leftover and clean up
	arr[count].append(temp);
	temp.clear();
}