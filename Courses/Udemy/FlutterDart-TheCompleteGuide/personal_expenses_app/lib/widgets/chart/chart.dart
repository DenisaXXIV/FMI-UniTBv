import 'package:flutter/material.dart';

import '../../models/expense.dart';
import 'chart_bar.dart';

class Chart extends StatelessWidget {
  const Chart({super.key, required this.expenses});

  final List<Expense> expenses;

  List<ExpenseBucket> get buckets {
    return [
      ExpenseBucket.forCategory(expenses, Categories.food),
      ExpenseBucket.forCategory(expenses, Categories.fees),
      ExpenseBucket.forCategory(expenses, Categories.leisure),
      ExpenseBucket.forCategory(expenses, Categories.transport),
      ExpenseBucket.forCategory(expenses, Categories.work),
    ];
  }

  double get maxTotalExpense {
    double maxTotalExpense = 0;

    for (final bucket in buckets) {
      if (bucket.totalExpenses > maxTotalExpense) {
        maxTotalExpense = bucket.totalExpenses;
      }
    }
    return maxTotalExpense;
  }

  Widget build(context) {
    final isDarkMode =
        MediaQuery.of(context).platformBrightness == Brightness.dark;

    return Container(
      margin: const EdgeInsets.all(16),
      padding: const EdgeInsets.symmetric(
        vertical: 16,
        horizontal: 8,
      ),
      width: double.infinity,
      height: 180,
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(8),
        gradient: LinearGradient(
          colors: [
            Theme.of(context).colorScheme.primary.withOpacity(0.3),
            Theme.of(context).colorScheme.primary.withOpacity(0.0),
          ],
          begin: Alignment.bottomCenter,
          end: Alignment.topCenter,
        ),
      ),
      child: Column(
        children:[
          Expanded(
            child: Row(
              crossAxisAlignment: CrossAxisAlignment.end,
              children: [
                for(final bucket in buckets)
                ChartBar(
                  fill:bucket.totalExpenses / maxTotalExpense,
                ),
              ],
            ),
          ),
          const SizedBox(height: 12,),
          Row(
            children: buckets
            .map(
              (bucket) => Expanded(
                child: Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 4),
                  child: Icon(categoryIcons[bucket.category],
                  color: isDarkMode
              ? Theme.of(context).colorScheme.secondary :Theme.of(context).colorScheme.primary.withOpacity(0.7),
              ),
               ),
          ),
          ).toList(),
          )
        ],
      ),
    );
  }
}