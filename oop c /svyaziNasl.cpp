//zadanie1
#include <iostream>
#include <string>

class Employee {
public:
    Employee(const std::string& name, double salary)
        : m_name(name), m_salary(salary) {}

    const std::string& getName() const { return m_name; }
    double getSalary() const { return m_salary; }

    virtual void printInfo() const {
        std::cout << "Сотрудник: " << m_name << ", Зарплата: " << m_salary << std::endl;
    }

protected:
    std::string m_name;
    double m_salary;
};

class Manager : public Employee {
public:
    Manager(const std::string& name, double salary, double bonus)
        : Employee(name, salary), m_bonus(bonus) {}

    double getBonus() const { return m_bonus; }

    void printInfo() const override {
        std::cout << "Менеджер: " << getName() << ", Зарплата: " << getSalary()
            << ", Надбавка: " << m_bonus << std::endl;
    }

private:
    double m_bonus;
};

int main() {
    setlocale(LC_ALL, "ru");
    Employee employee("Михаил Медведев", 50000);
    Manager manager("Владимир Уткин", 80000, 20000);

    Employee* pEmp1 = &employee;
    Employee* pEmp2 = &manager;

    pEmp1->printInfo();   
    pEmp2->printInfo();   

    return 0;
}
