import multiprocessing
import sys

def worker():
    name = multiprocessing.current_process().name
    print('Starting:', name)
    print('Doing some work...: ', name)
    print('Exiting :', name)

if __name__ == '__main__':

    n = multiprocessing.Process(
        name='worker1',
        target=worker,
    )
    n.start()
    print('doing something at main...')
    n.join()
