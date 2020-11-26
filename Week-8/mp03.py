import threading 
from Queue import Queue
import sys
import math

def isPrime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    max = int(math.ceil(math.sqrt(n)))
    i = 2
    while i <= max :
        if n % i == 0:
            return False
        i += 1
    return True

def sum_primes(n):
    return sum([x for x in xrange(2,n) if  isPrime(x)])

def do_work(q):
    while not q.empty():
        x = q.get(block=False)
        sum_primes(x)
    
if __name__ == '__main__':
    work_queue = Queue()
    for i in xrange(0,100000,500):
        work_queue.put(i)
        
    threads = [threading.Thread(target=do_work, args=(work_queue,)) for i in range(8)]
    for t in threads:
        t.start()
        
    for t in threads:
        t.join()
