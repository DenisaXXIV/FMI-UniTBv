import 'package:flutter/material.dart';
import 'package:personal_expenses_app/widgets/transaction_list/expenses_list.dart';

import '../models/expense.dart';
import 'chart/chart.dart';
import 'new_expense.dart';

class Expenses extends StatefulWidget {
  const Expenses({super.key});

  @override
  State<Expenses> createState() {
    return _ExpensesState();
  }
}

class _ExpensesState extends State<Expenses> {
  final List<Expense> _registeredExpenses = [
    Expense(
        title: 'Uber',
        amount: 7.80,
        category: Categories.transport,
        date: DateTime.now()),
    Expense(
        title: 'Flutter Courses',
        amount: 120.99,
        category: Categories.fees,
        date: DateTime.now()),
    Expense(
        title: 'Weekly Groceries',
        amount: 12.95,
        category: Categories.food,
        date: DateTime.now()),
    Expense(
        title: 'New Shoes',
        amount: 69.95,
        category: Categories.leisure,
        date: DateTime.now())
  ];

// method of adding an expense
  void _addExpenses(Expense expense) {
    setState(() {
      _registeredExpenses.add(expense);
    });
  }

// method for removing an expense
  void _removeExpense(Expense expense) {
    final expenseIndex = _registeredExpenses.indexOf(expense);
    setState(() {
      _registeredExpenses.remove(expense);
    });
    ScaffoldMessenger.of(context).clearSnackBars();
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        duration: const Duration(seconds: 3),
        content: const Text('Expense Deleted'),
        action: SnackBarAction(
          label: 'Undo',
          onPressed: () {
            setState(() {
              _registeredExpenses.insert(expenseIndex, expense);
            });
          },
        ),
      ),
    );
  }

  void _openAddExpenseOverlay() {
    showModalBottomSheet(
      isScrollControlled: true,
      useSafeArea: true,
      context: context,
      builder: (ctx) => NewExpense(onAddExpense: _addExpenses),
    );
  }

  @override
  Widget build(context) {
    final width = MediaQuery.of(context).size.width;

    Widget mainContent = const Center(
      child: Text(
        'No Expenses Found. Please add some!',
        style: TextStyle(fontSize: 18),
      ),
    );

    if (_registeredExpenses.isNotEmpty) {
      mainContent = ExpensesList(_registeredExpenses, _removeExpense);
    }
    
    return Scaffold(
      appBar: AppBar(
        title: const Text(
          'Personal Expenses App by Denisa',
          style: TextStyle(
              color: Color.fromARGB(255, 127, 226, 132),
              fontWeight: FontWeight.bold),
        ),
        actions: [
          IconButton(
            onPressed: _openAddExpenseOverlay,
            icon: const Icon(Icons.add),
          ),
        ],
      ),
      body: width < 600
          ? Column(
              children: [
                // Add ToolBar with Add button
                Chart(expenses: _registeredExpenses),
                Expanded(
                  child: mainContent,
                ),
              ],
            )
          : Row(
              children: [
                Expanded(
                  child: Chart(
                    expenses: _registeredExpenses
                  ),
                ),
                Expanded(
                  child: mainContent,
                ),
              ],
            ),
    );
  }
}