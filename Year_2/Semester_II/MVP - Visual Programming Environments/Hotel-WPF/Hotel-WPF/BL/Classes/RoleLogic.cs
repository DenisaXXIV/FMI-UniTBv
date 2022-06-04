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
    internal class RoleLogic : IEntityLogic<RoleDTO>
    {
        private readonly IHotelRepository<Role> _repository;
        private readonly IMapper _mapper;

        public RoleLogic(IHotelRepository<Role> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(RoleDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Role>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<RoleDTO>> GetAll()
        {
            var results = _mapper.Map<List<RoleDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(RoleDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdRole);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(RoleDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Role>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<RoleDTO> IEntityLogic<RoleDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
