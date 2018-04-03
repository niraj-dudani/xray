#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<vector<int>> read_bits(T value) {
	char* value_address = (char*) &value;
	int n_bytes = sizeof(value);
	vector<vector<int>> bytes;
	
	for (int i_byte = 0; i_byte < n_bytes; i_byte++) {
		char* byte_address = value_address + i_byte;
		char byte = *byte_address;
		
		vector<int> bits;
		for (int i_bit = 7; i_bit >= 0; i_bit--) {
			unsigned char mask = 1 << i_bit;
			unsigned char masked = byte & mask;
			unsigned char shifted = masked >> i_bit;
			int bit = static_cast<int>(shifted);
			
			bits.push_back(bit);
		}
		
		bytes.push_back(bits);
	}
	
	return bytes;
}

void show_bits(vector<vector<int>> bytes) {
	for(
		vector<vector<int>>::iterator i_byte = bytes.begin();
		i_byte != bytes.end();
		i_byte++
	) {
		for(
			vector<int>::iterator i_bit = i_byte->begin();
			i_bit != i_byte->end();
			i_bit++
		) {
			cout << *i_bit;
		}
		
		cout << endl;
	}
}

int main() {
	float x = 1.0;
	
	vector<vector<int>> bytes = read_bits(x);
	
	show_bits(bytes);
	
	return 0;
}
