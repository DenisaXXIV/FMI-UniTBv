using AutoMapper;
using Hotel_WPF.BL.Interfaces;
using Hotel_WPF.DAL.Entities;
using Hotel_WPF.DAL.Interfaces;
using Hotel_WPF.TL.DTO;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.BL.Classes
{
    internal class UserLogic : IEntityLogic<UserDTO>
    {
        private readonly IHotelRepository<User> _repository;
        private readonly IMapper _mapper;

        public UserLogic(IHotelRepository<User> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(UserDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<User>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<UserDTO>> GetAll()
        {
            var results = _mapper.Map<List<UserDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(UserDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdUser);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(UserDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<User>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<UserDTO> IEntityLogic<UserDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
