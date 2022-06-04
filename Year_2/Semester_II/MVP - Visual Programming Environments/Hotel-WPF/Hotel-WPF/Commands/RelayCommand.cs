using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Hotel_WPF.Commands
{
    internal class RelayCommand : ICommand
    {
        private Action<object> commandTask;
        private Predicate<object> canExecuteTask;

        public RelayCommand(Action<object> toDo) : this(toDo, DefaultCanExecute)
        {
            commandTask = toDo;
        }

        public RelayCommand(Action<object> toDo, Predicate<object> canExecute)
        {
            commandTask = toDo;
            canExecuteTask = canExecute;
        }

        private static bool DefaultCanExecute(object parameter)
        {
            return true;
        }
        public bool CanExecute(object parameter)
        {
            return canExecuteTask != null && canExecuteTask(parameter);
        }

        public event EventHandler CanExecuteChanged
        {
            add
            {
                CommandManager.RequerySuggested += value;
            }

            remove
            {
                CommandManager.RequerySuggested -= value;
            }
        }

        public void Execute(object parameter)
        {
            commandTask(parameter);
        }
    }
}
