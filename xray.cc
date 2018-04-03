#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<int> read_bits(T value) {
	char* value_address = (char*) &value;
	int n_bytes = sizeof(value);
	vector<int> bits;
	
	for (int i_byte = 0; i_byte < n_bytes; i_byte++) {
		char* byte_address = value_address + i_byte;
		char byte = *byte_address;
		
		for (int i_bit = 7; i_bit >= 0; i_bit--) {
			unsigned char mask = 1 << i_bit;
			unsigned char masked = byte & mask;
			unsigned char shifted = masked >> i_bit;
			int bit = static_cast<int>(shifted);
			
			bits.push_back(bit);
		}
	}
	
	return bits;
}

void show_bits(vector<int> bits) {
	for(int i = 0; i < bits.size(); i++) {
		cout << bits[i];
		
		if((i + 1) % 8 == 0) {
			cout << endl;
		}
	}
}

int main() {
	float x = 1.0;
	
	vector<int> bits = read_bits(x);
	
	show_bits(bits);
	
	return 0;
}
