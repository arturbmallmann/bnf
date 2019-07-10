#!/usr/bin/python3
#import ler
import sys

class state():
	def __init__(self,name):
		self.name=name
		self.next=dict()
		self.is_final=False
	def add_next(self,simbol,next_state):
		if(self.next.__contains__(simbol)):
			next_state = list(self.next[simbol])+[next_state]
		self.next.update({simbol:(next_state)})
#		print(" %s  %s  |  %s" % (self.name,simbol,next_state))
	def get_dict(self):
		return self.next

	def __iter__(self):
		return self.next.__iter__()
	def get_valueof(self,value):
		return self.next[value]
	def compute(self,simbol):
		return self.next.get(simbol)

	def get_name(self):
		return self.name
		
class language():
	def __init__(self):
		self.states = list() 
		self.initial = "S"
		self.add_state(state(self.initial))
		self.actual = self.initial
		self.name_counter = ord('A');
	def add_state(self,state):
		self.states.append(state)

	def get_state(self,value):
		for i in self.states:
			if (i.get_name()==value):
				return i
		return None
	def del_state(self,value):
		self.states.remove(value)
	def __iter__(self):
		return self.states.__iter__()
	def add_exp_next(self,simbol):
		sta=self.get_state(self.actual)
#		if(sta == None):
#			sta=state(self.actual)
#		self.add_state(sta)
		thenext=chr(self.name_counter)
		statnext=state(thenext)
		self.add_state(statnext)
		sta.add_next(simbol,thenext)
		self.actual=thenext
		self.name_counter+=1
	def reset_actual(self):
		self.actual=self.initial
	def is_running(self):
		aux=self.astate.get_name()
		return False if aux=="qsim" or aux=="qnao" else True
	def print_states(self):
		for i in self.states:
			final='*' if i.is_final else ''
			print("%s%s > %s" %(final,i.get_name(),i.get_dict()))

def main():
	args=sys.argv
#	inputFile = ler.File(args.pop())
	inputFile = open(args.pop())
#	print ('Lendo o arquivo %s' % (inputFile.name()))

	lang = language()
	for line in inputFile:
		line=line.strip()
		if (line==''):
			pass		
		else:
			if (line.find("::=")>0):
				splited = line.split("::=")
				a=splited[0].index('<')
				b=splited[0].index('>')
				sta= state((splited[0])[a+1:b].strip())
				lang.add_state(sta)
				
				transitions = splited[1].split('|')
		#		print ("%s \n %s" % (splited[0],transitions))
				for item in transitions:
					item=item.strip()
					#a=item.index('<')
					try:
						a=item.index('<');
						b=item.index('>');
						name=item[0:a].strip()#limpa espaços inúteis no início fim e repetidos
						nt=item[a+1:b].strip()
						sta.add_next(name,nt)
		#				b=slice(item.index('<')+1,item.index('>'))
		#				print ("name %s = nt %s" % (name,nt))
					except:
						'"nothing"'
					if(item=='ε'):
						sta.is_final=True
				print (sta.get_dict())
			else:
				#carga a partir dos tokens
				lang.reset_actual()
				for char in line:
					lang.add_exp_next(char)
				print("\nafter "%s" exp load:"%(line))
				lang.print_states()			
				

	print ("\nthe states before determinized:")
	lang.print_states();
	while True:#do while
		ans=determinizar(lang)#enquanto houver indeterminismo 
		print ("\n after:")
		lang.print_states();
		if ans:
			break
def determinizar(lang):
	flag=True
	for stat in lang:
		for key in stat:
			item = stat.get_valueof(key)
#			print("key %s value %s" %(key,item))
			if isinstance(item,list):
				flag=False #houveram alteracoes
				newname = ''.join(['[']+ item + [']'])
				stat.get_dict().update({key:newname})
				sta = state(newname)
				lang.add_state(sta)
				newdict=dict()
				for x in item:
					xstat = lang.get_state(x)
					for xkey in xstat:
						xitem = xstat.get_valueof(xkey)
						sta.add_next(xkey,xitem)
					sta.is_final = sta.is_final or xstat.is_final
					lang.del_state(xstat)
#				print(newname)

	return flag
#	m=machine(q['q0'],q,tape)
#	i=0
#	while(m.is_running()):
#		i+=1
#		print ("Ciclo %d %s\n"% (i,tape))
#		m.compute()
#states[1].add_transaction('>',self,'
#	states[0].
if __name__=='__main__':
	main()
