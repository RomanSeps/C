// C++ code
//
#define LM 12
#define PM 11
#define LED 13
#define TL 2

int i;
int state;

void setup()
{
  	pinMode(LM, OUTPUT);
  	pinMode(PM, OUTPUT);
  	pinMode(LED, OUTPUT);
  	pinMode(TL, INPUT);
  
  	
	state = 0;
  	Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0){
  	i = Serial.read();
  }
  
  switch(state){
  	case 0:
    	digitalWrite(LM, LOW);
    	digitalWrite(PM, LOW);
    	digitalWrite(LED, LOW);
    
        if(i == 'R'){
          state = 1;
        }else if(i == 'P'){
            state = 2;
        }else if(i == 'L'){
            state = 3;
        }
        break;
    
    case 1:
    	digitalWrite(LM, HIGH);
    	digitalWrite(PM, HIGH);
    
    	if(i == 'SR'){
    		state = 0;
    	}
    	
    	if(digitalRead(TL) == 1){
    		state = 4;
    	}
    	break;
    
    case 2:
    	digitalWrite(LM, HIGH);
    	digitalWrite(PM, LOW);
    
    	if(i == 'SP'){
        	state = 0;
        }
    	break;
    
    case 3:
    	digitalWrite(LM, LOW);
    	digitalWrite(PM, HIGH);
    
    	if(i == 'SL'){
        	state = 0;
        }
    	break;
    
    case 4:
    	digitalWrite(LED, HIGH);
        if(digitalRead(TL) == 0){
        	state = 0;
        }
    	break;
  }
}
