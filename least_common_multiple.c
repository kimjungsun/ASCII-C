# 2020_01_09_C_Algorithms
# copy_right_Megan
# Less_Common_Multiple
# constraints : arrays[n] 1<=n<=15   each element is less than 100 .
# main ideas : We know that prime numbers are 2,3,5,7 whose Squared are smaller than 100. 
               So we only need to figure out if the element has a factor as 2,3,5,7.

int solution(int arr[], size_t arr_len) {
    int answer = 1;    // set initally as 1 since it will be multiplied by others not added.
    int count=-1;   // count-bound concepts as a Semaphore in OS so that we can avoid counting a prime again or not.
    int bound=0;
   int prime[4]={2,3,5,7};
   int res[4]={1,1,1,1};
   for(int i=0;i<4;i++){
       count = -1;
       for(int j=0;j<arr_len;j++){
           bound = 0;
           while(arr[j]%prime[i]==0){
               arr[j]=arr[j]/prime[i];
               if(count<bound){
               res[i] *= prime[i];
                   count++;
               }
               bound++;
           }
       }   
   }
    for(int k=0;k<arr_len;k++)
        answer *= arr[k];

     for(int h=0;h<4;h++)
         answer *= res[h];
    return answer;
}
