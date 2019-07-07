#!/usr/bin/python3
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
#    tape=['>','0','0','1','1','0','0']+['_']*10
    print("insira uma palavra composta por 0s e 1s, separados por ',': ")
    tape=['>']
    tape+=input().split(',')
    tape+=['_']
    q={     'qsim'      :state('qsim'),
            'qnao'      :state('qnao'),
            'q0'        :state('q0'),
            'qachou0'   :state('qachou0'),
            'qbusca0'   :state('qbusca0'),
            'qachou1'   :state('qachou1'),
            'qbusca1'   :state('qbusca1'),
            'qvolta'    :state('qvolta')}

    q['qvolta'].add_transaction     ('>',   q['q0'],        '>',    right)
    q['q0'].add_transaction         ('>',   q['q0'],        '>',    right)
    q['qvolta'].add_transaction     ('0',   q['qvolta'],    '0',    left)
    q['qvolta'].add_transaction     ('1',   q['qvolta'],    '1',    left)

    q['q0'].add_transaction         ('0',   q['qachou0'],   '>',    right)
    q['q0'].add_transaction         ('1',   q['qachou1'],   '>',    right)
    q['q0'].add_transaction         ('_',   q['qsim'],      '_',    stop)

    q['qachou0'].add_transaction    ('0',   q['qachou0'],   '0',    right)
    q['qachou0'].add_transaction    ('1',   q['qachou0'],   '1',    right)
    q['qachou0'].add_transaction    ('_',   q['qbusca0'],   '_',    left)

    q['qbusca0'].add_transaction    ('0',   q['qvolta'],    '_',    left)
    q['qbusca0'].add_transaction    ('1',   q['qnao'],      '0',    stop)
    q['qbusca0'].add_transaction    ('>',   q['qsim'],      '>',    stop)

    q['qachou1'].add_transaction    ('0',   q['qachou1'],   '0',    right)
    q['qachou1'].add_transaction    ('1',   q['qachou1'],   '1',    right)
    q['qachou1'].add_transaction    ('_',   q['qbusca1'],   '_',    left)

    q['qbusca1'].add_transaction    ('1',   q['qvolta'],    '_',    left)
    q['qbusca1'].add_transaction    ('0',   q['qnao'],      '0',    stop)
    q['qbusca1'].add_transaction    ('>',   q['qsim'],      '>',    stop)
    print ('lol')
    m=machine(q['q0'],q,tape)
    i=0
    while(m.is_running()):
        i+=1
        print ("Ciclo %d %s\n"% (i,tape))
        m.compute()
    #states[1].add_transaction('>',self,'
#    states[0].
if __name__=='__main__':
    main()
