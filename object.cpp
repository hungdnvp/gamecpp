#include<iostream>
class Phu_nu{
    public:
        std:: string ho_ten;
        Phu_nu(std::string name,bool z){
            ho_ten= name;
            con_zin = z;
        }
       virtual std::string choi_nhac_cu(std::string nhac_cu)
        {
            return "AAAAAAA";
        }
    private:
        bool con_zin;
};
// kế thừa
class Gai_ngoan: public Phu_nu
{
    public:
    // constructor
    Gai_ngoan(std::string name,bool z)
        : Phu_nu(name,z)
    {}
    std::string choi_nhac_cu(std::string nhac_cu)
        {
            return "oooooo";
        }
};
int main(){
    Phu_nu *maria_ozawa = new Phu_nu("Maria Ozawa",true);
    // contro
    Phu_nu *oki = new Gai_ngoan("oki",false);
    std::cout<<oki->choi_nhac_cu("ken")<<std::endl;
}