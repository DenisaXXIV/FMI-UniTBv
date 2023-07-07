import 'package:flutter/material.dart';
import 'package:roll_dice_app/gradient_container.dart';

void main() {
  runApp(
    const MaterialApp(
      home: Scaffold(
        // backgroundColor: Color.fromARGB(255, 102, 18, 247),
        body: GradientContainer(
          colors: [
            Color.fromARGB(255, 28, 6, 107),
            Color.fromARGB(255, 79, 15, 116),
          ],
        ),
      ),
    ),
  );
}