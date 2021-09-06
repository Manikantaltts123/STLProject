/**
 * @file displaybill.cxx
 * @author Manikanta Suri (manikanta.suri@ltts.com)
 * @brief  function which displays bill of customer
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "CubeEatery.h"
/**
 * @brief Function which displays the final bill of customer according to user's order
 * 
 * @param price_map 
 * @param final_price 
 * @param is_member 
 * @param member_option 
 */
void displaybill(std::map<std::string,std::vector<Bill>>& price_map,float& final_price, bool is_member, char member_option)
{
    std::cout<<"\t\t\t\t\t\t\t\tCubeEATERY Bill"<<std::endl;
    std::map<std::string,std::vector<Bill>>::iterator bill_iter;
    /**
     * Display bill fields
     **/
     std::cout<<std::left
            <<std::setw(25)<<"Item ID"
            <<std::setw(25)<<"Item Name"
            <<std::setw(25)<<"Item Size"
            <<std::setw(25)<<"Item Cost(in Rs)"
            <<std::setw(25)<<"Qunatity"
            <<std::setw(25)<<"Total Price(in Rs)"<<std::endl;
    for(bill_iter=price_map.begin();bill_iter!=price_map.end();++bill_iter)
    {
        if(bill_iter->second[0].getoccurance())
        {
            /**
             * Display user's selected items
             **/    
            std::cout<<std::left
            <<std::setw(25)<<bill_iter->second[0].get_item_id()
            <<std::setw(25)<<bill_iter->second[0].get_item_name()
            <<std::setw(25)<<bill_iter->second[0].get_item_size()
            <<std::setw(25)<<bill_iter->second[0].get_item_cost()
            <<std::setw(25)<<bill_iter->second[0].getoccurance()
            <<std::setw(25)<<bill_iter->second[0].getprice()<<std::endl;
        }
    }
    /**
     * Display GST
     **/
    std::cout<<std::left        
            <<std::setw(25)<<"GST"
            <<std::setw(25)<<""
            <<std::setw(25)<<""
            <<std::setw(25)<<"3%"
            <<std::setw(25)<<""
            <<std::setw(25)<<0.03*final_price<<std::endl;
    final_price*=1.03;
    if(member_option=='y')
    {
        /**
        * Display Membership charges
        **/     
       std::cout<<std::left
            <<std::setw(25)<<"Membership charges"
            <<std::setw(25)<<""
            <<std::setw(25)<<""
            <<std::setw(25)<<""
            <<std::setw(25)<<""
            <<std::setw(25)<<"1500"<<std::endl; 
    final_price+=1500; 
    }
    if(is_member)
    {
       /**
        * Discount if user has membership
        **/     
       std::cout<<std::left
            <<std::setw(25)<<"Discount"
            <<std::setw(25)<<""
            <<std::setw(25)<<""
            <<std::setw(25)<<"5%" 
            <<std::setw(25)<<""
            <<std::setw(25)<<0.05*final_price<<std::endl;
    final_price*=0.95; 
    }
    /**
     * Display final price
     **/
    std::cout<<std::left
            <<std::setw(25)<<"Grand Total"
            <<std::setw(25)<<""
            <<std::setw(25)<<""
            <<std::setw(25)<<""
            <<std::setw(25)<<""
            <<std::setw(25)<<final_price<<std::endl;
}
