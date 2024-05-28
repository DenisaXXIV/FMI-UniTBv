package com.denisaxxiv.dinnerdecider

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.denisaxxiv.dinnerdecider.databinding.ActivityMainBinding

abstract class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.selectedFoodTxt.text = "Burger King"
    }
}