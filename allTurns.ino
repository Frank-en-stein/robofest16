// turn select
void nolineTurnSelect() {
  if(left90 && right90) {
    if(!leftPrefer) LeftTurn();
    else RightTurn();
  }
  else if(leftPrefer && left90) LeftTurn();
  else if(!leftPrefer && right90) RightTurn();
  else if(left90) LeftTurn();
  else if(right90) RightTurn();
  else if(outOfLine == leftOut) LeftTurn();
  else if(outOfLine == rightOut) RightTurn();
                   
  outOfLine =  notOut;
  left90=right90=false;//delay(50);
}

void intersectionTurnSelect() {
  if(left90 && right90) {
    if(leftPrefer) intersection_LeftTurn();
    else intersection_RightTurn();
  }
  else if(leftPrefer && left90) intersection_LeftTurn();
  else if(!leftPrefer && right90) intersection_RightTurn();
  else if(left90) intersection_LeftTurn();
  else if(right90) intersection_RightTurn();
  else if(outOfLine == leftOut) intersection_LeftTurn();
  else if(outOfLine == rightOut) intersection_RightTurn();
  else wheel(200,200);
        
  outOfLine =  notOut;
  left90=right90=false;//delay(50);  
}
//turn select ends

//turns
void RightTurn(){
//  wheel(200,200);
//  delay(30);
  while(!((analogRead(C) > threshhold[3]) ? !blackline:blackline)){
    wheel(120,-120);
  }
  wheel(-200,200);
  delay(20);
  wheel(0,0);
  delay(15);
  while(!((analogRead(C) > threshhold[3]) ? !blackline:blackline)){
    wheel(-70,70);
  }
//  irUpdate();
//  while(S[5]+S[6]>0){
//    wheel(-90, 90);
//    irUpdate();
//  }
  stop();
  delay(10);
  //wheel(THROTTLE, THROTTLE);
  //delay(50);
}
void LeftTurn(){
//  wheel(200,200);
//  delay(30);                 
  while(!((analogRead(C) > threshhold[3]) ? !blackline:blackline)){
    wheel(-120,120);
  }
  wheel(200,-200);
  delay(20);
  wheel(0,0);
  delay(15);
  while(!((analogRead(C) > threshhold[3]) ? !blackline:blackline)){
    wheel(70,-70);
  }
//  irUpdate();
//  while(S[0]+S[1]>0){
//    wheel(90, -90);
//    irUpdate();
//  }
  stop();
  delay(10);
  //wheel(THROTTLE, THROTTLE);
  //delay(50);
}

void intersection_RightTurn(){
//  wheel(200,200);
//  delay(25);
//  stop();
//  delay(10);
  //if(irUpdate()>2) blindRight90();
  while(!((analogRead(R) > threshhold[5]) ? !blackline:blackline)){
    wheel(120,-120);
    
  }
  while(!((analogRead(C) > threshhold[3]) ? !blackline:blackline)){
    wheel(90,-90);
  }
  
  wheel(-255,255);
  delay(10);
  wheel(0,0);
  delay(15);
  
  //delay(5000);
}
void intersection_LeftTurn(){
//  wheel(200,200);
//  delay(25);
//  stop();
//  delay(10);
  //if(irUpdate()>2) blindLeft90();
  while(!((analogRead(L) > threshhold[1]) ? !blackline:blackline)){
    wheel(-120,120);
   
  }
  while(!((analogRead(C) > threshhold[3]) ? !blackline:blackline)){
    wheel(-90,90);
   
  }
  wheel(255,-255);
  delay(10);
  wheel(0,0);
  delay(15);
  
  //delay(5000);
}


void blindLeft90() {
  hardbrake();
  delay(10);
  wheel(-100, 100);
  delay(380);
  
  wheel(100, -100);
  delay(50);
  wheel(0,0);
  delay(50);
}

void blindRight90() {
  hardbrake();
  delay(10);
  wheel(100, -100);
  delay(380);
  
  wheel(-100, 100);
  delay(50);
  wheel(0,0);
  delay(50);
}
//turns end

