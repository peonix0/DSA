// checking for valid parentheses using stack
// (A+B)+(C)+D)     : Invalid

#include "../stack_using_simple_array.cpp"

bool valid_or_not(string Str){
  int n = Str.length();
  stack *S = create_stack(n);
  for(int i=0;i<n;i++){
    if(Str[i]==')' || Str[i]=='('){
      if(Str[i]==')' && char(top(S))=='(')
      {
        pop(S);
      }
      else if(isEmpty(S) && Str[i]==')'){
        return false;
      }
      else{
        push(S,int(Str[i]));
      }
    }
  }
  if(size(S)){
    return false;
  }
  else{
    return true;
  }
}

//test

int main(){
  string str = "A+(B)+(C))";
  bool output = valid_or_not(str);
  if(output){
    cout <<"\n~ Valid parentheses ~\n";
  }
  else{
    cout <<"\n~ Invalid parentheses ~\n";
  }
}
