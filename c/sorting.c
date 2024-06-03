void sort(int number[],int count){
   int temp;
   for(int i=0;i<count;i++){
      for(int j=i+1;j<count;j++){
         if(number[i]>number[j]){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
   }
}