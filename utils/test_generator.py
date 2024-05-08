from abc import ABC,abstractmethod

class Test_Generator(ABC):

    @abstractmethod
    def get_input(self):
        pass
    
    def write_output(self):
        pass
