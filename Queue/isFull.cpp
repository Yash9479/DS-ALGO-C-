/*begin procedure isfull

   if rear equals to MAXSIZE
      return true
   else
      return false
   endif
   
end procedure*/


bool isfull() {
   if(rear == MAXSIZE - 1)
      return true;
   else
      return false;
}