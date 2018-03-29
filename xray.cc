#include <iostream>

using namespace std;

int main() {
	float x = 1.0;
	
	char* x_address = (char*) &x;
	int n_bytes = sizeof(x);
	
	for (int i_byte = 0; i_byte < n_bytes; i_byte++) {
		char* byte_address = x_address + i_byte;
		char byte = *byte_address;
		
		cout << i_byte << " ";
		
		for (int i_bit = 7; i_bit >= 0; i_bit--) {
			unsigned char mask = 1 << i_bit;
			unsigned char masked = byte & mask;
			unsigned char bit = masked >> i_bit;
			
			//~ cout << (int) mask << " " << (int) masked << " " << (int) bit << endl;
			
			cout << (int) bit;
		}
		cout << endl;
	}
}
