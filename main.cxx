#include <iostream>
#include <string>
int calculate_checksum(const std::string& input) {
    int checksum = 0;
    for (char ch : input) {
        checksum += ch;
    }
    return checksum;
}
int calculate_key(int checksum, char first_char_of_arg1, size_t program_name_length) {
    return (checksum ^ first_char_of_arg1 * 3) << (program_name_length & 0x1f);
}
void print_checksum_and_key(int checksum, int calculated_key, int expected_value) {
    std::cout << "Calculated Checksum: " << checksum << std::endl;
    std::cout << "Calculated Key: " << calculated_key << std::endl;
    std::cout << "Expected Key: " << expected_value << std::endl;
}
void print_usage_instructions() {
    std::cout << "Usage: ./program_name <string> <expected_key>" << std::endl;
    std::cout << "Where:" << std::endl;
    std::cout << "<string> is the string input to calculate the checksum." << std::endl;
    std::cout << "<expected_key> is the expected integer key." << std::endl;
}
int main(int arg_count, char *arg_values[]) {
  bool has_not_correct_args = (arg_count != 3);
  if (has_not_correct_args) {
    std::cout << "Invalid number of arguments!" << std::endl;
        print_usage_instructions();
        return 1;
  }
  std::string program_name{arg_values[0]};
  char first_char_of_arg1{*(arg_values[1])};
  size_t program_name_length{program_name.size()};
  int expected_value{std::atoi(arg_values[2])};
  std::string first_input{arg_values[1]};
  int checksum = calculate_checksum(first_input);
  int calculated_key = calculate_key(checksum, first_char_of_arg1, program_name_length);
  print_checksum_and_key(checksum, calculated_key, expected_value);
  if (calculated_key == expected_value) {
    std::cout << "Correct!" << std::endl;
  } else {
    std::cout << "Wrong!" << std::endl;
  }
  return 0;
}