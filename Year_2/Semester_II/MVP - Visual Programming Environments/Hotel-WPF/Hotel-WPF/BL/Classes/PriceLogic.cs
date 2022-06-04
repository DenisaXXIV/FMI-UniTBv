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
    internal class PriceLogic : IEntityLogic<PriceDTO>
    {
        private readonly IHotelRepository<Price> _repository;
        private readonly IMapper _mapper;

        public PriceLogic(IHotelRepository<Price> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(PriceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Price>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<PriceDTO>> GetAll()
        {
            var results = _mapper.Map<List<PriceDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(PriceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdPrice);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(PriceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Price>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<PriceDTO> IEntityLogic<PriceDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
