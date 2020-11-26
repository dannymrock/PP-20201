import multiprocessing as mp
import sys

def worker(id):
    print('Starting:', id)
    print('Doing some work...: ', id)
    print('Exiting :', id)

if __name__ == '__main__':
    
    processes = [mp.Process(target=worker, args=[x]) for x in range(4)]
    for p in processes:
        p.start()
        
    print('doing something at main...')

    for p in processes:
        p.join()
