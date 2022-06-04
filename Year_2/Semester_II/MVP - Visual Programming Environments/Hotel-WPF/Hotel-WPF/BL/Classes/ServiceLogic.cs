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
    internal class ServiceLogic : IEntityLogic<ServiceDTO>
    {
        private readonly IHotelRepository<Service> _repository;
        private readonly IMapper _mapper;

        public ServiceLogic(IHotelRepository<Service> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(ServiceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Service>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<ServiceDTO>> GetAll()
        {
            var results = _mapper.Map<List<ServiceDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(ServiceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdService);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(ServiceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Service>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<ServiceDTO> IEntityLogic<ServiceDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
