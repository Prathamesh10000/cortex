// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
 
contract Bank {
    // balance of every customer, stored against the customer's address
    mapping(address => uint256) private balances;
 
    // Deposit money: the ether sent with the transaction is added to the balance
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than 0");
        balances[msg.sender] += msg.value;
    }
 
    // Withdraw money: reduce the balance and send the ether back to the customer
    function withdraw(uint256 amount) public {
        require(amount > 0, "Withdraw amount must be greater than 0");
        require(balances[msg.sender] >= amount, "Insufficient balance");
        balances[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
    }
 
    // Show balance of the customer who calls this function
    function showBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}
