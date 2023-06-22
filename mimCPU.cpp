#include <iostream>
#include <string>
#include <map>


namespace cminusminus{
// - - - - - - - - Forward Declare

    class whole;
    class decimal;
    class big_decimal;
    class thread;
    class letter;

// - - - - - - - - Simulate Memory

    template <typename universal> class CPU{
    protected:
        std::map <int, std::string> memory;
        int allocMemoryLocation;

    public:
        CPU(){allocMemoryLocation = 0;}

        template <typename T> void store(T data){
            // 😭 took the easy way out
            memory[allocMemoryLocation] = std::to_string(data);
            allocMemoryLocation++;
        }

        //have no idea how/why this works with the one above
        //forward declare does not work 
        void store(float data){ memory[allocMemoryLocation] = data; allocMemoryLocation++; }
        void store(double data){ memory[allocMemoryLocation] = std::to_string(data); allocMemoryLocation++; }
        void store(std::string data){ memory[allocMemoryLocation] = data; allocMemoryLocation++; }
        void store(char data){ memory[allocMemoryLocation] = data; allocMemoryLocation++; }

        void load(){
            if(allocMemoryLocation == 0){ std::cout<<"Nothing in memory."; }
            else{//displays all memory and values
                for(auto &oneLoc : memory){ std::cout<<" > "<<oneLoc.first<<" "<<oneLoc.second<<std::endl; }
            }
        }

        void load(int ui){
            if(ui <= getAddr()){std::cout<<memory.at(ui);}
            else{std::cout<<"Where you going? Memory spot "<<ui<<" does not contain anything."<<std::endl;}
        }

        int getAddr(){return allocMemoryLocation;}
    };

    CPU<std::string>manageMem;// - - ChatGPT

// - - - - - - - - data type classes

    class whole{
        friend std::ostream &operator<<(std::ostream &output, whole num);
        friend std::istream &operator>>(std::istream &input, whole &i);
        friend thread operator+(whole num, thread str);
    private:
        int value;
        int loc;
    public:
        whole(){ value = 0; loc = manageMem.getAddr(); }

        // - - - [Assignment Operations]

        whole operator=(int num){ this->value = num; manageMem.store(num); return *this; }
        whole operator=(whole num){ this->value = num.value; manageMem.store(num.value); return *this; }

        // - - - [Mathmatical Operations]
        
        whole operator+(int &num){ whole result; result.value = this->value + num; manageMem.store(num); return result; }
        whole operator+(whole &num){ whole result; result.value = this->value + num.value; manageMem.store(num.value); return result; }
        whole operator-(int &num){whole result; result.value = this->value - num; manageMem.store(num); return result;}
        whole operator-(whole &num){ whole result; result.value = this->value - num.value; manageMem.store(num.value); return result; }      
        whole operator*(int &num){ whole result; result.value = this->value * num; manageMem.store(num); return result; }
        whole operator*(whole &num){ whole result; result.value = this->value * num.value; manageMem.store(num.value); return result; }
        whole operator/(int &num){ whole result; result.value = this->value / num; manageMem.store(num); return result; }
        whole operator/(whole &num){ whole result; result.value = this->value / num.value; manageMem.store(num.value); return result; }        

        // - - - [Boolean Operations]

        bool operator==(int num){ manageMem.store(num); return this->value == num; }
        bool operator==(whole num){ manageMem.store(num.value); return this->value == num.value; }
    };

    class decimal{
        friend std::ostream &operator<<(std::ostream &output, decimal num);
        friend std::istream &operator>>(std::istream &input, decimal &i);
        friend thread operator+(decimal num, thread str);
    private:
        float value;
        int loc;
    public:
        decimal(){ value = 0.00; loc = manageMem.getAddr(); }
        // - - - [Assignment Operations]

        decimal operator=(float num){ this->value = num; manageMem.store(num); return *this; }
        decimal operator=(decimal num){ this->value = num.value; manageMem.store(num.value); return *this; }

        // - - - [Mathmatical Operations]

        decimal operator+(float &num){ decimal result; result.value = this->value + num; manageMem.store(num); return result; }
        decimal operator+(decimal &num){ decimal result; result.value = this->value + num.value; manageMem.store(num.value); return result; }
        decimal operator-(float &num){ decimal result; result.value = this->value - num; manageMem.store(num); return result; }
        decimal operator-(decimal &num){ decimal result; result.value = this->value - num.value; manageMem.store(num.value); return result; }
        decimal operator*(float &num){ decimal result; result.value = this->value * num; manageMem.store(num); return result; }
        decimal operator*(decimal &num){ decimal result; result.value = this->value * num.value; manageMem.store(num.value); return result; }
        decimal operator/(float &num){ decimal result; result.value = this->value / num; manageMem.store(num); return result; }
        decimal operator/(decimal &num){ decimal result; result.value = this->value / num.value; manageMem.store(num.value); return result; }

        // - - - [Boolean Operations]

        bool operator==(float num){ manageMem.store(num); return this->value == num; }
        bool operator==(decimal num){ manageMem.store(num.value); return this->value == num.value; }
    };

    class big_decimal{
        friend std::ostream &operator<<(std::ostream &output, big_decimal num);
        friend std::istream &operator>>(std::istream &input, big_decimal &i);
        friend thread operator+(big_decimal num, thread str);
    private:
        double value;
        int loc;
    public:
        big_decimal(){value = 0.00; loc = manageMem.getAddr(); }
        // - - - [Assignment Operations]

        big_decimal operator=(double num){ manageMem.store(num); this->value = num; return *this; }
        big_decimal operator=(big_decimal num){ manageMem.store(num.value); this->value = num.value; return *this; }

        // - - - [Mathmatical Operations]

        big_decimal operator+(double &num){ big_decimal result; result.value = this->value + num; manageMem.store(num); return result; }
        big_decimal operator+(big_decimal &num){ big_decimal result; result.value = this->value + num.value; manageMem.store(num.value); return result; }
        big_decimal operator-(double &num){ big_decimal result; result.value = this->value - num; manageMem.store(num); return result; }
        big_decimal operator-(big_decimal &num){ big_decimal result; result.value = this->value - num.value; manageMem.store(num.value); return result; }
        big_decimal operator*(double &num){ big_decimal result; result.value = this->value * num; manageMem.store(num); return result; }
        big_decimal operator*(big_decimal &num){ big_decimal result; result.value = this->value * num.value; manageMem.store(num.value); return result; }
        big_decimal operator/(double &num){ big_decimal result; result.value = this->value / num; manageMem.store(num); return result; }
        big_decimal operator/(big_decimal &num){ big_decimal result; result.value = this->value / num.value; manageMem.store(num.value); return result; }

        // - - - [Boolean Operations]

        bool operator==(double num){ manageMem.store(num); return this->value == num; }
        bool operator==(big_decimal num){ manageMem.store(num.value); return this->value == num.value; }
    };

    class thread{
        friend std::ostream &operator<<(std::ostream &output, thread str);
        friend std::istream &operator>>(std::istream &input, thread &str);
        friend void countVowels(thread input);
        friend void reverseString(thread str);
        friend thread operator+(int num, thread str);
        friend thread operator+(whole num, thread str);
        friend thread operator+(float num, thread str);
        friend thread operator+(decimal num, thread str);
        friend thread operator+(double num, thread str);
        friend thread operator+(big_decimal num, thread str);
        friend thread operator+(char num, thread str);
        friend thread operator+(letter num, thread str);
    private:
        std::string value;
        int loc;
    public:
        thread(){value = ""; loc = manageMem.getAddr(); }
        // - - - [Assignment Operations]

        thread operator=(std::string str){ manageMem.store(str); this->value = str; return *this; }
        thread operator=(thread str){ manageMem.store(str.value); this->value = str.value; return *this; }

        // - - - [Concatenate Operations]
        // - [Note] | Forward Declaration doesn't work, cannot work with namespace data types

        thread operator+(int &num){ thread result; result.value = this->value + std::to_string(num); manageMem.store(num); return result; }
        thread operator+(float &num){ thread result; result.value = this->value + std::to_string(num); manageMem.store(num); return result; }
        thread operator+(double &num){ thread result; result.value = this->value + std::to_string(num); manageMem.store(num); return result; }
        thread operator+(std::string &str){ thread result; result.value = this->value + str; manageMem.store(str); return result; }
        thread operator+(thread &str){ thread result; result.value = this->value + str.value; manageMem.store(str.value); return result; }

        // - - - [Boolean Operations]

        bool operator==(std::string str){ manageMem.store(str); return this->value == str; }
        bool operator==(thread str){ manageMem.store(str.value); return this->value == str.value; }
    };

    class letter{
        friend std::ostream &operator<<(std::ostream &output, letter charc);
        friend std::istream &operator>>(std::istream &input, letter &charc);
        friend thread operator+(letter num, thread str);
    private:
        char value;
        int loc;
    public:
        letter(){}
        // - - - [Assignment Operations]
        
        letter operator=(char charc){  this->value = charc; return *this; }
        letter operator=(letter charc){ this->value = charc.value; return *this; }

        // - - - [Concatenate Operations]

        letter operator+(char &charc){ letter result; result.value = this->value + charc; manageMem.store(charc); return result; }
        letter operator+(letter &charc){ letter result; result.value = this->value + charc.value; manageMem.store(charc.value); return result; }

        // - - - [Boolean Operations]

        bool operator==(char charc){ manageMem.store(charc); return this->value == charc; }
        bool operator==(letter charc){ manageMem.store(charc.value); return this->value == charc.value; }
    };

// - - - - - - - - concatenate all types to a string, var + string

    thread operator+(int num, thread str){thread result; result.value = std::to_string(num) + str.value; return result;}
    thread operator+(whole num, thread str){thread result; result.value = std::to_string(num.value) + str.value; return result;}
    thread operator+(float num, thread str){thread result; result.value = std::to_string(num) + str.value; return result;}
    thread operator+(decimal num, thread str){thread result; result.value = std::to_string(num.value) + str.value; return result;}
    thread operator+(double num, thread str){thread result; result.value = std::to_string(num) + str.value; return result;}
    thread operator+(big_decimal num, thread str){thread result; result.value = std::to_string(num.value) + str.value; return result;}
    thread operator+(char num, thread str){thread result; result.value = std::to_string(num) + str.value; return result;}
    thread operator+(letter num, thread str){thread result; result.value = std::to_string(num.value) + str.value; return result;}

// - - - - - - - - output stream

    std::ostream &operator<<(std::ostream &output, whole num){ output<<num.value; return output; }
    std::ostream &operator<<(std::ostream &output, decimal num){ output<<num.value; return output; }
    std::ostream &operator<<(std::ostream &output, big_decimal num){ output<<num.value; return output; }
    std::ostream &operator<<(std::ostream &output, thread str){ output<<str.value; return output; }
    std::ostream &operator<<(std::ostream &output, letter charc){ output<<charc.value; return output;}

// - - - - - - - - input stream

    std::istream &operator>>(std::istream &input, whole &i){ input>>i.value; return input; }
    std::istream &operator>>(std::istream &input, decimal &i){ input>>i.value; return input; }
    std::istream &operator>>(std::istream &input, big_decimal &i){ input>>i.value; return input; }
    std::istream &operator>>(std::istream &input, thread &str){ input>>str.value; return input; }
    std::istream &operator>>(std::istream &input, letter &charc){ input>>charc.value; return input;}

// - - - - - - - - display fns

    template <typename universal>
        void showme(universal i){std::cout<<i;}//take in 1
    template <typename T1, typename T2> 
        void showme(T1 value1, T2 value2){std::cout<<value1<<value2;}//take in 2
    template <typename T1, typename T2, typename T3>
        void showme(T1 value1, T2 value2, T3 value3){std::cout<<value1<<value2<<value3;}//take in 3
    template <typename T1, typename T2, typename T3, typename T4>
        void showme(T1 value1, T2 value2, T3 value3, T4 value4){std::cout<<value1<<value2<<value3<<value4;}//take in 4
    template <typename T1, typename T2, typename T3, typename T4, typename T5>
        void showme(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5){std::cout<<value1<<value2<<value3<<value4<<value5;}//take in 5
    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        void showme(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6)
            {std::cout<<value1<<value2<<value3<<value4<<value5<<value6;}//take in 6

// - - - - - - - - input fns

    template <typename universal> universal readin(){universal x; std::cin>>x; return x;}
    template <typename universal> universal readin(universal x){std::cin>>x; return x;}
    std::string readline(){std::string x; std::getline(std::cin, x); return x;}
    std::string readline(thread &x){std::string input; getline(std::cin, input); x = input; return input;} // - - ChatGPT

// - - - - - - - - format fns

    void newline(){std::cout<<std::endl;}
    void newline(int num){for(int x = 0; x < num; x++){std::cout<<std::endl;}}
    void f_dash(){std::cout<<"--  --  --  --  --  --  --  --  --  --  --  --  --  --"<<std::endl;}
    void f_s_dash(){std::cout<<"--  --  --  --  --  --  --"<<std::endl;}
    void indent(){std::cout<<"\t";}
    void catchE(){getchar();}

// - - - - - - - - fun fns

    void countVowels(std::string input){
        std::string vowels = "aeiou";
        int numVowels = 0;
        for(char oneChar : input){for(char isVowel : vowels){if(oneChar == isVowel){numVowels++;}}}
        std::cout<<"Number of vowels: "<<numVowels<<std::endl;
    }

    void countVowels(thread input){
        std::string vowels = "aeiou";
        int numVowels = 0;
        for(char oneChar : input.value){for(char isVowel : vowels){if(oneChar == isVowel){numVowels++;}}}
        std::cout<<"Number of vowels: "<<numVowels<<std::endl;
    }

    void reverseString(std::string str){
        std::string rString; int x = str.length();
        while(x != 0){ x--; rString += str[x]; }
        std::cout<<"Your Reversed String: \n> |\t"<<rString;
    }

    void reverseString(thread str){
        std::string rString; int x = str.value.length();
        while(x != 0){ x--; rString += str.value[x]; }
        std::cout<<"Your Reversed String: \n> |\t"<<rString;
    }

// - - - - - - - - rename C++ functions

    //pulled from stack overflow/bing
    #define ifit(condition) if(condition)
    #define elif(condition) else if(condition)
    #define el(condition) else(condition)

}// - - - - - - - - [end namespace] - - - - - - - - 

using namespace cminusminus;

int main(){

    //  use instructions to create your own program or
    //  use the mini pre-create ones at the bottom of 
    //  instructions
    return 0;
}