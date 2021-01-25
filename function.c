int situp(float X, float Y, int *STATE,float* situp_num){
  //detect situp
    if ((X> -9.3) &&(X< -8.5)&&(*STATE == 1)){
     //laying down
    (*situp_num)++;
    (*STATE)--;
    return 1;
    } else if((Y <9.5)&&(Y>9.3)&&(*STATE == 0)){
      //get up
    (*situp_num)++;
    (*STATE)++;
    return 2;
  }
  return 0;
}

int squat(float X, float* squat_num, int* STATE){
  //detect squat
  if ((X> -9.3) &&(X< -8.5)&&(*STATE == 0)){
    //stand up
    (*squat_num)++;
    (*STATE)++;
    return 1;
  } else if((X < -10)&&(*STATE == 1)){
    //going up
    (*STATE)--;
    (*squat_num)++;
    return 2;
  }
  return 0;
}

int pushup(float X, float Y, int* STATE,float* pushup_num){
  //detect pushup
   if ((X> -9.3)&&(X< -8.5)&&(*STATE == 0)){
    //holding up
      (*pushup_num)++;
      (*STATE)++;
      return 1;
    }else if ((Y> -9.3)&&(Y< -8.5)&&(*STATE == 1)){
      //buttom of the push
      (*pushup_num)++;
      (*STATE)--;
      return 2;
    }
    return 0;
}

int jjacks(float X, float Y, float Z,int* STATE, float* jumpjack_num){
  //detect jjacks
   if ((X > -9.3)&&(X < -8.5)&&(*STATE == 0)){
    //hands down
      (*jumpjack_num)++;
      (*STATE)++;
      return 1;
   }else if ((X > 1)&&(Z > 5)&&(*STATE == 1)){
    //hands up
      (*jumpjack_num)++;
      (*STATE)--;
      return 2;
    }
    return 0;
}
