# PAGE REPLACEMENT TECHNIQUE FOR CACHE 
# DIWAS ADHIKARI (076BEI014)

# Least Recently Used (LRU)
import time

def searchInList(array, num):
	for i in range(len(array)):
		if(num == array[i]):
			return i
	return -1

def LRU():
    # Getting number of page frames 
    pageFrames = int(input("Input the number of page frames for cache: "))
    temp = 0
    blocks = []
    counters = []
    cache = []
    lru = []
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
            print("Status(", blocks[i], ") : " )
            index = searchInList(cache, blocks[i]) 
            if(index != -1):
                print("HIT")
                counters[index] += 1
                lru.remove(blocks[i])
                lru.append(blocks[i]) # This shuffle puts the page recently used at end of lru list i.e. lru[last index] 
            else:
                pageFaults += 1
                print("MISS")
                if(len(cache) < pageFrames):
                    cache.append(blocks[i])
                    counters.append(1)
                    lru.append(blocks[i])

                else:
                    # LRU Replacement
                    first = lru[0]
                    index = searchInList(cache, first)
                    cache[index] = blocks[i]
                    counters[index] = 0
                    lru.append(blocks[i])

            print("Cache \t\t Occurences")
            print(cache, "\t", counters)
            print("---------------------------------------------------")
    print("Page Faults: ", pageFaults)

LRU()
			
