using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.BL.Interfaces
{
    public interface IEntityLogic<T> where T : class
    {
        Task<List<T>> GetAll();
        Task<T> GetByName(string name);
        Task Add(T entityDTO);
        Task Update(T entityDTO);
        Task Remove(T entityDTO);
    }
}
