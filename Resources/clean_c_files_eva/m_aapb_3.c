assigns \nothing;
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  
  
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      
      
      
      if (cur[0] == 'A') {
        id = 1;
        
        
        m = 1;
      } else {
        
      }
    } else if (id == 1) {
      
      
      if (cur[0] == 'A') {
        
        id = 1;
        
        m = 1;
      } else if (cur[0] == 'B') {
        
        id = 2;
        
        
        m = 1;
      } else {
        
        
        
        
        
      }
    } else if (id == 2) {
      
      
      
      
      
      
      
      
      
      
    } else {
      
    }
    cur++;
    
  }
  int res = id==2 && cur[0]=='\0' && m;
  
  return res;
}

int main(void)
{
    char s_var = 'x';
    m_aapb(&s_var);
    return 0;
}
