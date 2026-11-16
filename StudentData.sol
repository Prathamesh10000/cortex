// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
 
contract StudentData {
    // Structure: one student record
    struct Student {
        uint256 rollNo;
        string name;
        uint256 marks;
    }
 
    // Array: list of all students
    Student[] public students;
 
    // counts how many times the fallback function was executed
    uint256 public fallbackCalls;
 
    // add a new student to the array
    function addStudent(uint256 _rollNo, string memory _name, uint256 _marks) public {
        students.push(Student(_rollNo, _name, _marks));
    }
 
    // get the student stored at the given index
    function getStudent(uint256 index) public view
        returns (uint256, string memory, uint256)
    {
        require(index < students.length, "Student not found");
        Student memory s = students[index];
        return (s.rollNo, s.name, s.marks);
    }
 
    // total number of students
    function getCount() public view returns (uint256) {
        return students.length;
    }
 
    // Fallback: runs when a function that does not exist is called
    fallback() external payable {
        fallbackCalls++;
    }
 
    // receive: runs when ether is sent with no data
    receive() external payable {}
}
