from abc import ABC,abstractmethod

class Writer:
    def __init__(self):
        pass

    def write_output(self,filename,*args,arr):
        file = open(filename)
        
        list_str = lambda x : "\n".join(list(map(str,x)))

        arg = list_str(args)
        lines = list_str(arr)
        file.writelines(arg)
        file.writelines("START\n")
        file.writelines(lines)

        file.close()





