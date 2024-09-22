# PAGE REPLACEMENT TECHNIQUE FOR CACHE 
# DIWAS ADHIKARI (076BEI014)

# First In First Out (FIFO)

def searchInList(array, num):
	for i in range(len(array)):
		if(num == array[i]):
			return i
	return -1

def FIFO():
    # Getting number of page frames 
    pageFrames = int(input("Input the number of page frames for cache: "))
    temp = 0
    blocks = []
    counters = []
    cache = []
    first = 0
    pageFaults = 0

    # Prompting page sequence
    while(1):
        temp = input() 
        if(temp == 's'):
                break
        blocks.append(int(temp))

    # Cache Blocks & Counters
    for i in range(len(blocks)):
            print("Status: ")
            index = searchInList(cache, blocks[i])
            if(index != -1):
                print("HIT")
                counters[index] += 1
            else:
                pageFaults += 1
                print("MISS")
                if(len(cache) < pageFrames):
                    cache.append(blocks[i])
                    counters.append(1)
                else:
                    # FIFO Replacement
                    first = first % pageFrames
                    cache[first] = blocks[i]
                    counters[first] = 0
                    first += 1
                    
            print("Cache \t\t Occurences")
            print(cache, "\t", counters)
            print("---------------------------------------------------")
    print("Page Faults: ", pageFaults)
FIFO()
			
