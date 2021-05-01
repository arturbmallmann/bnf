#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

//sort:
//#include <functional>
#include <algorithm>
struct {
	char * ID;
	char * data;
	int size;
} typedef my_data;
class State {
		std::array<std::array<my_data,100>,100> table;
		std::string name;
		bool is_final;
     public:
     State(std::string name){
 		this->name=name;
// 		self.next=dict();
 		this->is_final=false;
     };
};
// 	State::add_next(self,simbol,next_state){
// 		if(self.next.__contains__(simbol)):
// 			next_state = list(self.next[simbol])+[next_state]
// 		self.next.update({simbol:(next_state)})
// print(" %s  %s  |  %s" % (self.name,simbol,next_state))
//     }
// 	def get_dict(self):
// 		return self.next
// 
// 	def __iter__(self):
// 		return self.next.__iter__()
// 	def get_valueof(self,value):
// 		return self.next[value]
// 	def compute(self,simbol):
// 		return self.next.get(simbol)
// 
// 	def get_name(self):
// 		return self.name
// }
// class language():
// 	def __init__(self):
// 		self.states = list() 
// 		self.initial = "S"
// 		self.add_state(state(self.initial))
// 		self.actual = self.initial
// 		self.name_counter = ord('A');
// 	def add_state(self,state):
// 		self.states.append(state)
// 
// 	def get_state(self,value):
// 		for i in self.states:
// 			if (i.get_name()==value):
// 				return i
// 		return -1 
// 	def del_state(self,value):
// 		self.states.remove(value)
// 	def __iter__(self):
// 		return self.states.__iter__()
// 	def add_exp_next(self,simbol):
// 		sta=self.get_state(self.actual)
// #		if(sta == None):
// #			sta=state(self.actual)
// #		self.add_state(sta)
// 		thenext=chr(self.name_counter)
// 		statnext=state(thenext)
// 		self.add_state(statnext)
// 		sta.add_next(simbol,thenext)
// 		self.actual=thenext
// 		self.name_counter+=1
// 	def reset_actual(self):
// 		self.actual=self.initial
// 	def is_running(self):
// 		aux=self.astate.get_name()
// 		return False if aux=="qsim" or aux=="qnao" else True
// 	def print_states(self):
// 		for i in self.states:
// 			final='*' if i.is_final else ''
// 			print("%s%s > %s" %(final,i.get_name(),i.get_dict()))
using namespace std;
void bnf(char * f_name){
    ifstream arquivo; // ifstream (ler) ofstream(gravar) fstream(ler e gravar)
 /*   arquivo.open(entries,std::ios::in);
    char aaa[100];
	while(arquivo>>aaa){
        cout<<aaa;
    }
	if (argc > 1){
		arquivo.open(argv[argc-2]);
		do{
//:			buffer<<aaa;
			//arquivo>>aaa;
//			cout<<aaa;
		}while(!arquivo.eof());
	}
	arquivo.close();*/
	arquivo.open(f_name,std::ios::in);
//	arquivo.seekg(0);
//	char buff [255];
	string line;
	string inputFile;
	while (getline(arquivo,line) ){
//		cout<<"line length:"<<buff.length()<<" last: "<<buff[buff.length()-1]<<endl;
		while(line[0]==' ')
			line.erase(0,1);
		while(line[line.length()-1]==' ')
			line.erase(line.length()-1,1);
		int p=0;
//		cout<<buff.find("  ")<<endl;
		while( (int) line.find(" ") != -1 ){
			p = (int) line.find(" ");
			cout<<"P: "<<p<<endl;
			line.erase(p,1);
		}
		//inputFile += buff +'\n';
		if (line==""){
			continue;
		}
		cout<<line<<endl;
		array<char,100> nterm;//nao terminais
		int i_count=0; 
		array<char,100> transactions;//transicões
		char * name; // nome da regra
//		for (int i=0;i<100;i++)
//			name[0] = '\n';
		p=0;
		if((int)line.find("::=")!=-1){
			p=line.find("::=") + 3;
//			name = buff.
			int beg=(int)line.find('<')+1;
			int end=(int)line.find('>');
			name = (char*)malloc(sizeof(char)*end-beg+1);
			cout<<"beg: "<<beg<<" end: "<<end<<endl;
			line.copy(name,end-beg,beg);
			name[end-beg]='\n';
			cout<<"name: "<<name<<" ..."<<endl;
			while((int)line.find("<",p+1) != -1){
				p = line.find("<",p+1);
				nterm[i_count++]=line[p-1];
				transactions[i_count++]=line[p+1];
			}
		//	sort(inputs.begin(),inputs.end(), std::greater<char>());
			cout<<"size: "<<nterm.size()<<endl;
		//	sort(inputs.begin(),inputs.end(), std::greater<char>());
			sort(nterm.begin(),nterm.begin()+i_count);//), std::less<char>());
//			sort(inputs.begin(),inputs.begin()+i_count,[](int a, int b) {
//                return a < b;
//            });
		}
		else{
			cout<<"tokens\n";
		}
		cout<<"chars:\n";
		for(auto it = nterm.begin(); it != nterm.begin()+i_count;it++)
			cout<<*it<<" ";
		cout<<endl;
	//}
	//cout<<"Input File:\n"<<inputFile<<endl;

	//while(!arquivo.eof());
/*	char ** lang = malloc(100*100);
		line=line.strip()
		if (line==''):
			pass		
		else:
			if (line.find("::=")>0):
				splited = line.split("::=")
				a=splited[0].index('<')
				b=splited[0].index('>')
				rule_name=(splited[0])[a+1:b].strip()
				sta=lang.get_state(rule_name)
				if (sta == -1):
					print("criando %s" % (rule_name))
					sta=state(rule_name)
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
				lang.get_state(lang.actual).is_final=True
#				print("\nafter "%s" exp load:" % (line))
				lang.print_states()			

	print ("\nthe states before determinized:")
	lang.print_states();
	while True:#do while
		ans=determinizar(lang)#enquanto houver indeterminismo 
		print ("\n after:")
		lang.print_states();
		if ans:
			break*/
	}	
}
int determinizar(char ** lang){
	bool flag=true;
// 	for stat in lang:
// 		for key in stat:
// 			item = stat.get_valueof(key)
// #			print("key %s value %s" %(key,item))
// 			if isinstance(item,list):
// 				flag=False #houveram alteracoes
// 				newname = ''.join(['[']+ item + [']'])
// 				stat.get_dict().update({key:newname})
// 				sta = state(newname)
// 				lang.add_state(sta)
// 				newdict=dict()
// 				print("item %s" %(item))
// 				try:#de algum jeito o is instance as vezes falhas, sei lá pq, try nele...
// 					for x in item:
// 						xstat = lang.get_state(x)
// 						for xkey in xstat:
// 							xitem = xstat.get_valueof(xkey)
// 							sta.add_next(xkey,xitem)
// 						sta.is_final = sta.is_final or xstat.is_final
// 						lang.del_state(xstat)
// 				except:
// 					pass
// #				print(newname)
// 
 	return flag;
}
using namespace std;
int main(int argc, char ** argv){
	char * f_name = argv[argc-1];
	stringstream buffer;
    cout<<f_name<<'['<<argc<<']'<<endl;
    bnf(f_name);
}
// #	m=machine(q['q0'],q,tape)
// #	i=0
// #	while(m.is_running()):
// #		i+=1
// #		print ("Ciclo %d %s\n"% (i,tape))
// #		m.compute()
// #states[1].add_transaction('>',self,'
// #	states[0].
// if __name__=='__main__':
// 	main()
