#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iterator>

class SalesPerson {
    private:
        std::string name;
        std::string title;
        std::vector<double> sales;

    public:
        SalesPerson(const std::string& name, const std::string& title, const std::vector<double>& sales)
            : name(name), title(title), sales(sales) {}
        
        std::string getName() const {
            return name;
        }

        std::string getTitle() const {
            return title;
        }

        std::vector<double> getSales() const {
            return sales;
        }

        std::vector<double>::iterator iterSales() {
            return sales.begin();
        }

        double totalSales() const {
            return std::accumulate(sales.begin(), sales.end(), 0);
        }

        double minSales() const {
            return *std::min_element(sales.begin(), sales.end());

        }

        double maxSales() const {
            return *std::max_element(sales.begin(), sales.end());
        }

        double averageSales() const {
            return totalSales() / sales.size();
        }
};

void salesReport(const std::vector<SalesPerson>& salesPeople) {
    double companyTotal = 0.0;
    for (const auto& person : salesPeople) {
        std::cout << "Name: " << person.getName() << ", Title: " << person.getTitle() << std::endl;
        std::cout << "Total Sales: $" << person.totalSales() << std::endl;
        std::cout << "Minimum Sales: $" << person.minSales() << std::endl;
        std::cout << "Maximum Sales: $" << person.maxSales() << std::endl;
        std::cout << "Average Sales: $" << person.averageSales() << std::endl;
        std::cout << "-----------------------------" << std::endl;
        companyTotal += person.totalSales();
    }
    std::cout << "Total Sales for the Company: $" << companyTotal << std::endl;
}

int main() {
    std::vector<SalesPerson> salesPeople;

    for (int i = 0; i < 3; ++i) {
        std::string name;
        std::string title;
        std::vector<double> sales(3);

        std::cout << "Enter name for sales person #" << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Enter title for sales person #" << i + 1 << ": ";
        std::cin >> title;

        std::cout << "Enter 3 sales figures for " << name << ": " << std::endl;

        for (size_t i = 0; i < sales.size(); ++i) {
            double& sale = sales[i];
            std::cout << "Sale figure " << i+1 << ": ";
            std::cin >> sale;
        }
        salesPeople.emplace_back(name, title, sales);
    }
    std::cout << "Finished collecting data. Preparing to generate the sales report..." << std::endl;
    std::cin.get();
    salesReport(salesPeople);
    std::cin.get();
    std::cout << "Press enter to quit.";
    std::cin.get();
    return 0;
}