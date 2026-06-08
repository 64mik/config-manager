#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H
#include <string>
#include <initializer_list>
#include <map>
class ConfigManager {
    public:
        enum class ConfigType { INT, STRING, BOOL, FLOAT };   // 설정값의 유형을 정의하는 열거형
        ConfigManager() : ConfigManager("config.conf") {}   // 기본 파일명으로 생성자 호출
        ConfigManager(const std::string& filename);
        ~ConfigManager();
        void loadConfig();   // 파일에서 설정값을 읽어와 맵에 저장하는 기능
        void saveConfig();

        void setAsBool(const bool defaultValue);
        void setAsInt(const int start, const int end, const int defaultValue);
        void setAsString(const std::initializer_list<std::string>& values);
        void setAsFloat(const float start, const float end, const float defaultValue);
        
  /*
    맵이 되었든 변수가 되었든 자체적으로 설정값을 맵으로 저장해두고 호출을 도움
    설정 변경이나 업데이트를 위한 API 제공
   v  현 설정을 파일에 저장하는 기능
    true false 나 숫자에 문자 넣기 처럼 규격에 맞지 않는 입력값은 경고 내보내고 기본값 설정하는 기능
    생성자 매개변수로 파일명 받아서 여는 기능 
    설정값을 쉽게 정의할 수 있도록 돕는 기능?

    int A = 5 
    string B = "hi" 처럼 .conf에 저장
    아 그래 기본값을 정할 때, 서브모듈 config에서 규격을 받아오는거지 ex: width=config::int(5,1)	//0~5사이의 정수값을 정상 설정값으로 가짐. 기본값 1
    실행시 런타임 실행값이 out of range면 여기에 적힌 값으로 기본값을 정하는거지

    순환 문제 조심
    범위는 자동으로 위에 주석을 달아 표기해주고
    범위는 런타임에 호출된 setAs를 통해 맵에 저장되고, 수정불가. 
    불러오기로는 값이 유효하면 적용하는 기능으로 제한
    

    */

    private:
        void validateConfig(const std::string& key, const std::string& value);   // 설정값의 유효성을 검사하는 기능
        void setDefaultConfig();   // 기본 설정값을 맵에 저장하는 기능
        std::string fileName_;
        std::map<std::string, std::string> configMap_;
};
#endif // CONFIG_MANAGER_H