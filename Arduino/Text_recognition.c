int state;
int input;

void setup()
{
	state = 0;
  	Serial.begin(9600); // BPS
}


void loop()
{
  if(Serial.available() > 0){
  	input = Serial.read();
  }
  
  switch(state){
  	case 0:
      if(input == 'a'){
        state = 1;
      }
    	break;
    
    case 1:
    	if(input == 'h'){
        	state = 2;
      	}
    	break;
    
    case 2:
    	if(input == 'o'){
        	state = 3;
     	}
    	break;
    
    case 3:
    	if(input == 'j'){
       	 state = 0;
          Serial.println("Tesi me");
      	}
    	break;
    
    
  }
    
}
