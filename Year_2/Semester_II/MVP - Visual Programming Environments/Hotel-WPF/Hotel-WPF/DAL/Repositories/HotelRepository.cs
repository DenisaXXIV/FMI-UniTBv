using Hotel_WPF.DAL.Interfaces;
using Hotel_WPF.DAL.Migrations;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace Hotel_WPF.DAL.Repositories
{
    public class HotelRepository<T> : IHotelRepository<T> where T : class
    {
        private readonly HotelDbContext _context;

        public HotelRepository(HotelDbContext context)
        {
            _context = context;
        }
        public async Task<T> Add(T entity)
        {
            if (entity != null)
            {
                _context.Set<T>().Add(entity);
                await _context.SaveChangesAsync();
                return entity;
            }
            throw new DbUpdateException();
        }

        public async Task<T> Delete(int id)
        {
            var entity = await _context.Set<T>().FindAsync(id);
            if (entity == null)
            {
                return null;
            }
            try
            {
                _context.Set<T>().Remove(entity);
                await _context.SaveChangesAsync();
                return entity;
            }
            catch (DbUpdateException)
            {
                throw;
            }
            catch (Exception)
            {
                throw;
            }
        }

        public async Task<T> Get(int id)
        {
            if (id <= 0)
            {
                throw new ArgumentException(nameof(id));
            }
            return await _context.Set<T>().FindAsync(id);
        }

        public async Task<List<T>> GetAll()
        {
            return await _context.Set<T>().ToListAsync();
        }



        public async Task<T> Update(T entity)
        {
            if (entity == null)
            {
                throw new ArgumentNullException(nameof(entity));
            }
            try
            {
                //_context.Entry(entity).State = EntityState.Modified;
                await _context.SaveChangesAsync();
                return entity;
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }
    }
}
