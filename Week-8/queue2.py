from multiprocessing import Process, Queue, current_process

def worker(task, results):
    t = task.get()
    result = t * 2
    results.put([current_process().name,t,"*",2,"=",result])
    
if __name__ == '__main__':
    n = 100
    myTasks = Queue()
    myResults = Queue()

    processes = [Process(target=worker, args=(myTasks, myResults)) for i in range(n)]
    
    for p in processes:
        p.start()
    
    for item in range(n):
        myTasks.put(item)

    for i in range(n):
        result = myResults.get()
        print("Res: ", result)
        
