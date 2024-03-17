#include <iostream>
#include <vector>
#include <string>

class Job {
public:
    std::string title;
    std::string description;
    std::string company;

    Job(const std::string& title, const std::string& description, const std::string& company)
        : title(title), description(description), company(company) {}
};

class JobPortal {
private:
    std::vector<Job> jobs;

public:
    void addJob(const std::string& title, const std::string& description, const std::string& company) {
        jobs.emplace_back(title, description, company);
        std::cout << "Job added successfully!\n";
    }

    void viewJobs() {
        std::cout << "Available Jobs:\n";
        for (const auto& job : jobs) {
            std::cout << "Title: " << job.title << "\n";
            std::cout << "Description: " << job.description << "\n";
            std::cout << "Company: " << job.company << "\n\n";
        }
    }

    void applyForJob(const std::string& title) {
        for (auto& job : jobs) {
            if (job.title == title) {
                std::cout << "You have successfully applied for the job: " << job.title << "\n";
                return;
            }
        }
        std::cout << "Job not found!\n";
    }
};

int main() {
    JobPortal jobPortal;

    while (true) {
        std::cout << "1. Add Job\n";
        std::cout << "2. View Jobs\n";
        std::cout << "3. Apply for a Job\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, description, company;
                std::cout << "Enter job title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter job description: ";
                std::getline(std::cin, description);
                std::cout << "Enter company name: ";
                std::getline(std::cin, company);
                jobPortal.addJob(title, description, company);
                break;
            }
            case 2:
                jobPortal.viewJobs();
                break;
            case 3: {
                std::string title;
                std::cout << "Enter the title of the job you want to apply for: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                jobPortal.applyForJob(title);
                break;
            }
            case 4:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

