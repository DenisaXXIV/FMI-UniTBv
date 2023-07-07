import 'package:uuid/uuid.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart'; 

final formatter = DateFormat.yMd();

const uuid = Uuid();

enum Categories { transport, food, fees, leisure, work}

const categoryIcons = {
  Categories.food: Icons.lunch_dining,
  Categories.transport: Icons.flight_takeoff_rounded,
  Categories.leisure: Icons.movie_rounded,
  Categories.fees: Icons.money_rounded,
  Categories.work: Icons.work,
};

class Expense {
  Expense({
      required this.title, 
      required this.amount, 
      required this.date,
      required this.category,
    }) :id = uuid.v4();


  final String id;
  final String title;
  final double amount;
  final DateTime date;
  final Categories category;

  //use getters
  get formattedDate {
    return formatter.format(date);
  }
}
// the dashboard class
class ExpenseBucket {
      
    const ExpenseBucket(
      {
        required this.category, 
        required this.expenses
      }
    );

    // Alternative constructor for filtering expenses belonging to a specific category
    ExpenseBucket.forCategory(List<Expense> allExpenses, this.category) 
    : expenses = allExpenses.where(
        (expense) => expense.category == category
      ).toList();

     final Categories category;
     final List<Expense> expenses;

     double get totalExpenses {
        double sum = 0;
      // looping through the expenses 
      for(final expense in expenses ){
          // sum = sum  + expense.amount;
          sum += expense.amount;
      }
        return sum;
     }
  }

