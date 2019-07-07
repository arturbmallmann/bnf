#!/usr/bin/python3
import ler
import sys
left=-1
right=1
stop=0
class state():
    def __init__(self,name):
        self.name=name
        self.next=dict()

    def add_transaction(self,simbol,next_state,write,direction):
        self.next.update({simbol:(next_state,write,direction)})
        print(" %s  %s  | (   %s, %s, %d)" % (simbol,self.name,write,next_state.get_name(),direction))

    def compute(self,simbol):
        return self.next.get(simbol)

    def get_name(self):
        return self.name

class machine():
    def __init__(self,q0,states,tape):
        print("maquina criada")
        self.states=states
        self.astate=q0
        self.tape=tape
        self.position=0

    def add_state(self,state):
        self.append(states)

    def compute(self):
        print("Position: %s Estado: %s" % (self.position,self.astate.get_name()))
        (self.astate,
        self.tape[self.position],
        direction) = self.astate.compute(self.tape[self.position])        
        self.position+=direction
        print("Position+1: %s Estado+1: %s" % (self.position, self.astate.get_name()))
    def is_running(self):
        aux=self.astate.get_name()
        return False if aux=="qsim" or aux=="qnao" else True

def main():
	args=sys.argv
	inputFile = ler.File(args.pop());
	print ('Lendo o arquivo %s' % (inputFile.name()))

	while (lambda x : x=inputFile.read()):
		print(line)
#    m=machine(q['q0'],q,tape)
#	i=0
#    while(m.is_running()):
#        i+=1
#        print ("Ciclo %d %s\n"% (i,tape))
#        m.compute()
    #states[1].add_transaction('>',self,'
#    states[0].

if __name__=='__main__':
    main()

