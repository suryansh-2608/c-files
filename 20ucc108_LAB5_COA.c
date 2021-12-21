#include <stdio.h>
#include <math.h>
void binaryCache(int decimal) {
	int binary[10];
	int i = 0;
	while (decimal > 0) {
		binary[i++] = decimal % 2;
		decimal /= 2;
	}
	int j = i-1;
	for( j; j >=0; j--) {
		printf("%d", binary[j]);
	}
	printf("\n");
}
void binary(int decimal) {
	int binary[10];
	int i = 0;
	while (decimal > 0) {
		binary[i++] = decimal % 2;
		decimal /= 2;
	}
	for(i; i<10; i++) {
		binary[i] = 0;
	}
	int j = i-1;
	for( j; j >=0; j--) {
		printf("%d", binary[j]);
	}
	printf("\n");
}
int main() {

	const int mainMemory = 8192;
	const int mainMemoryize = 8;
	const int cacheWord = 2048;
	const int cachePerBlock = 4;
	int mainMemoryBytesPerWord = mainMemoryize / 8;
	int cacheBytesPerBlock = cachePerBlock * mainMemoryize / 8;
	int offsetSize = log(cacheBytesPerBlock)/log(2);
	int setSize = log(mainMemory)/log(2);
	int cacheBlocks = cacheWord / cachePerBlock;
	int tagSize = setSize  - log(cacheBlocks)/log(2) - log(cachePerBlock)/log(2);
	int memoryAddress;
	printf("\n");
	printf("No. of blocks in cache are: %d\n", cacheBlocks);
	printf("No. of bits required for word is: %.0f\n", log(cachePerBlock)/log(2));   
	printf("No. of bits required for block is: %.0f\n", log(cacheBlocks)/log(2));
	printf("No. of bits for tag is: %d\n", tagSize);
	printf("\nEnter memory address(k): ");
	scanf("%d", &memoryAddress);
	printf("Equivalent binary value of k: ");
	binary(memoryAddress); 
	printf("Main memory block: %d\n", memoryAddress / mainMemoryBytesPerWord);
	printf("Cache block: %d\n", memoryAddress % cacheBlocks);
	printf("Word Address: ");
	binaryCache(((memoryAddress % cacheBlocks) * 2 - 1) + memoryAddress % 2 - 1);
	printf("Block Address: ");
	binaryCache((memoryAddress % cacheBlocks));
}
